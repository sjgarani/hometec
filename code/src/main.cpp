#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>
#include "statemachine.hpp"

#define DAEMON_NAME "hometec"

void daemon_shutdown();
void signal_handler(int sig);
void daemonize(const char *rundir, const char *pidfile);

bool exit_daemon = false;
int pid_file_handle;

void signal_handler(int sig) {
  switch (sig) {
  case SIGINT:
  case SIGTERM:
    exit_daemon = true;
    break;
  }
}

void daemon_shutdown() {
  syslog(LOG_INFO, "Hometec daemon exiting...");
  close(pid_file_handle);
}

void daemonize(const char *rundir, const char *pidfile) {
  int pid, sid, i;
  char str[10];
  struct sigaction sig_action;
  sigset_t sig_set;

  if (getppid() == 1) {
    return;
  }

  /* Set signal mask - signals we want to block */
  sigemptyset(&sig_set);
  sigaddset(&sig_set, SIGCHLD);
  sigaddset(&sig_set, SIGTSTP);
  sigaddset(&sig_set, SIGTTOU);
  sigaddset(&sig_set, SIGTTIN);
  sigprocmask(SIG_BLOCK, &sig_set, NULL);

  sig_action.sa_handler = signal_handler;
  sigemptyset(&sig_action.sa_mask);
  sig_action.sa_flags = 0;

  sigaction(SIGHUP, &sig_action, NULL);
  sigaction(SIGTERM, &sig_action, NULL);
  sigaction(SIGINT, &sig_action, NULL);

  pid = fork();
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(027); /* Set file permissions 750 */

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  for (i = getdtablesize(); i >= 0; --i) {
    close(i);
  }

  /* Route I/O connections */
  i = open("/dev/null", O_RDWR);

  dup(i);

  dup(i);

  chdir(rundir);

  /* Ensure only one copy */
  pid_file_handle = open(pidfile, O_RDWR | O_CREAT, 0600);

  if (pid_file_handle == -1) {
    syslog(LOG_INFO, "Could not open PID lock file %s, exiting!", pidfile);
    exit(EXIT_FAILURE);
  }

  /* Try to lock file */
  if (lockf(pid_file_handle, F_TLOCK, 0) == -1) {
    syslog(LOG_INFO, "Could not lock PID lock file %s, exiting!", pidfile);
    exit(EXIT_FAILURE);
  }

  /* Get and format PID */
  sprintf(str, "%d\n", getpid());

  /* write pid to lockfile */
  write(pid_file_handle, str, strlen(str));
}

int main() {

  setlogmask(LOG_UPTO(LOG_INFO));
  openlog(DAEMON_NAME, LOG_CONS | LOG_PERROR, LOG_USER);

  syslog(LOG_INFO, "Hometec daemon starting up...");

  const char *daemonpid = "/var/run/hometec.pid";
  const char *daemonpath = "/";
  daemonize(daemonpath, daemonpid);

  syslog(LOG_INFO, "Hometec daemon running...");

  Module sw;
  sw.initiate();

  while (!exit_daemon) {
    sleep(10);
  }

  syslog(LOG_INFO, "Hometec daemon exiting...");
}

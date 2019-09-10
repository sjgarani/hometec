FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://journald.conf"
SRC_URI += "file://eth.network"

FILES_${PN} += "{sysconfdir}/systemd/network/*"

PACKAGECONFIG += "networkd resolved timesyncd hostnamed polkit myhostname"

# for version 230 yocto fixes this
# networkd requires a user
USERADD_PARAM_${PN} += "--system -d / -M --shell /bin/nologin systemd-network;"
# resolved requires a user
USERADD_PARAM_${PN} += "--system -d / -M --shell /bin/nologin systemd-resolve;"
# timesyncd requires a user
USERADD_PARAM_${PN} += "--system -d / -M --shell /bin/nologin systemd-timesync;"

do_install_append() {
        cp ${WORKDIR}/journald.conf ${D}${sysconfdir}/systemd
        install -d ${D}${sysconfdir}/systemd/network/
        install -m 0644 ${WORKDIR}/*.network ${D}${sysconfdir}/systemd/network/
}
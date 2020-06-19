%%%-------------------------------------------------------------------
%% @doc hometec top level supervisor.
%% @end
%%%-------------------------------------------------------------------

-module(hometec_sup).

-behaviour(supervisor).

-export([start_link/0]).

-export([init/1]).

-define(SERVER, ?MODULE).

start_link() ->
    ChildSpecs = [{hometec_log, {hometec, start_link, []}, permanent, brutal_kill, worker, [hometec]}],
    supervisor:start_link({local, ?SERVER}, ?MODULE, ChildSpecs).

%% sup_flags() = #{strategy => strategy(),         % optional
%%                 intensity => non_neg_integer(), % optional
%%                 period => pos_integer()}        % optional
%% child_spec() = #{id => child_id(),       % mandatory
%%                  start => mfargs(),      % mandatory
%%                  restart => restart(),   % optional
%%                  shutdown => shutdown(), % optional
%%                  type => worker(),       % optional
%%                  modules => modules()}   % optional
init(ChildSpecs) ->
    SupFlags = #{strategy => one_for_all,
                 intensity => 0,
                 period => 1},
    {ok, {SupFlags, ChildSpecs}}.

%% internal functions

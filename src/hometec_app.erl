%%%-------------------------------------------------------------------
%% @doc hometec public API
%% @end
%%%-------------------------------------------------------------------

-module(hometec_app).

-behaviour(application).

-export([start/2, stop/1]).

start(_StartType, _StartArgs) ->
    hometec_sup:start_link().

stop(_State) ->
    ok.

%% internal functions

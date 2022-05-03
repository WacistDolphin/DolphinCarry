#include "../plugin_sdk/plugin_sdk.hpp"
#include "Kalista.h"

PLUGIN_NAME("KalistaCarry");
SUPPORTED_CHAMPIONS(champion_id::Kalista);

PLUGIN_API bool on_sdk_load(plugin_sdk_core* plugin_sdk_good)
{
    DECLARE_GLOBALS(plugin_sdk_good);

    switch (myhero->get_champion()) {
    case champion_id::Kalista:
        Kalista::load();
        break;
    default:
        console->print("Champion %s is not supported!", myhero->get_model_cstr());
        return false;
    }

    return true;
}

PLUGIN_API void on_sdk_unload( )
{
    switch (myhero->get_champion()) {
    case champion_id::Kalista:
        Kalista::unload();
        break;
    default:
        break;
    }
}
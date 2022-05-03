#include "../plugin_sdk/plugin_sdk.hpp"
#include "Kalista.h"
#include "KalistaCarry.h"
#include "KalistaDraw.h"

namespace Kalista {
	//void on_update();
	//void on_before_attack(game_object_script target, bool* process);

	void load() {
		KalistaCarry::load();
		KalistaDraw::loadMenu();
		event_handler<events::on_update>::add_callback(KalistaCarry::onUpdate);
	}

	void unload() {
		KalistaCarry::unload();
		event_handler<events::on_update>::remove_handler(KalistaCarry::onUpdate);
	}
}
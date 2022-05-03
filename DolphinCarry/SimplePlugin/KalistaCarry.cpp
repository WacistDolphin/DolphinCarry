#include "../plugin_sdk/plugin_sdk.hpp"
#include "KalistaCarry.h"

namespace KalistaCarry {
	void load() {
		script_spell* q = plugin_sdk->register_spell(spellslot::q, 1200);
		script_spell* w = plugin_sdk->register_spell(spellslot::w, 5000);
		script_spell* e = plugin_sdk->register_spell(spellslot::e, 1100);
		script_spell* r = plugin_sdk->register_spell(spellslot::r, 1100);
		q->set_skillshot(0.25, 80, 2400, { collisionable_objects::minions, collisionable_objects::heroes, collisionable_objects::yasuo_wall }, skillshot_type::skillshot_line);
	}

	void calcOverallDamage() {

	}


	void onUpdate() {

	}
}
#include "../plugin_sdk/plugin_sdk.hpp"

namespace KalistaCarry {
	script_spell* q = nullptr;
	script_spell* w = nullptr;
	script_spell* e = nullptr;
	script_spell* r = nullptr;

	void calcOverallDamage();
	void calcQDamage();
	void calcWDamage();
	void calcEDamage();
	void load();
	void unload();
	void onUpdate();
};
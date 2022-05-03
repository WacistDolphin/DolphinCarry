#include "../plugin_sdk/plugin_sdk.hpp"
#include "KalistaDraw.h"

namespace KalistaDraw {
#define Q_RANGE_COLOR (MAKE_COLOR(255, 255, 0, 255));
#define E_RANGE_COLOR (MAKE_COLOR(0, 0, 255, 255));
#define R_RANGE_COLOR (MAKE_COLOR(68, 0, 255, 255));

	TreeTab* mainTab = nullptr;

	namespace drawSettings {
		TreeEntry* drawQRange = nullptr;
		TreeEntry* drawERange = nullptr;
		TreeEntry* drawRRange = nullptr;
	};

	namespace smartLogic {
		TreeEntry* autoHarass = nullptr;
		TreeEntry* killStealWithQ = nullptr;
		TreeEntry* useFlashToKS = nullptr;

		// Smart R
		TreeEntry* belowHealthPerc = nullptr;
		TreeEntry* allyHealthPerc = nullptr;
		TreeEntry* rOutNumbered = nullptr;
		TreeEntry* rMinEnemies = nullptr;
		TreeEntry* useRAllyGank = nullptr;
	};

	namespace combo {
		TreeEntry* useQ = nullptr;
		TreeEntry* useE = nullptr;
	};

	namespace harass {
		TreeEntry* useQ = nullptr;
		TreeEntry* useQAboveMana = nullptr;
		TreeEntry* useE = nullptr;
		TreeEntry* useEAboveMana = nullptr;
		TreeEntry* useEAtXStacks = nullptr;
		TreeEntry* useEBeforeOutofRange = nullptr;
		TreeEntry* useEBeforeDeath = nullptr;
	};

	namespace laneClear {
		TreeEntry* useQ = nullptr;
		TreeEntry* useQMinMinions = nullptr;
		TreeEntry* useE = nullptr;
		TreeEntry* useEMinMinions = nullptr;
		TreeEntry* harassInLaneClear = nullptr;
	};

	void loadMenu() {
		const std::string heroModel = myhero->get_model();
		const std::string smartLogicS = heroModel + ".smartLogic";
		const std::string smartR = heroModel + ".smartR";

		mainTab = menu->create_tab("kalista", "Kalista Carry");
		mainTab->set_assigned_texture(myhero->get_square_icon_portrait());
		{
			auto smartLogic = mainTab->add_tab(smartLogicS, "Smart Logic");
			{
				smartLogic::autoHarass = smartLogic->add_checkbox(smartLogicS + ".autoHarass", "Auto Harass", true);
				smartLogic::killStealWithQ = smartLogic->add_checkbox(smartLogicS + ".ksWithQ", "Killsteal With Q", true);
				smartLogic::useFlashToKS = smartLogic->add_checkbox(smartLogicS + ".flashToKS", "Use Flash to KS", true);
				auto smartRConfig = smartLogic->add_tab(smartR, "Smart R Config");
				{
					smartLogic::belowHealthPerc = smartRConfig->add_checkbox(smartR + ".ifBelowPerc", "Save Ally When Below % Health", true);
					smartLogic::allyHealthPerc = smartRConfig->add_slider(smartR + ".allyHealthPerc", "Ally Health Percentage", 5, 3, 50);
					smartLogic::rOutNumbered = smartRConfig->add_checkbox(smartR + ".outnumbered", "Save Ally When Outnumbered", true);
					smartLogic::rMinEnemies = smartRConfig->add_slider(smartR + ".minEnemies", "If Outnumbered By", 2, 1, 3);
					smartLogic::useRAllyGank = smartRConfig->add_checkbox(smartR + ".allyGank", "Use R for Ally Gank", true);
				}
			}
		}
	}
};
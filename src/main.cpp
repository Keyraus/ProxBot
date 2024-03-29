//#include "MyBot.h"
#include "MyBotToken.hpp"
#include <dpp/dpp.h>
#include "visuals.hpp"
#include "command/ping.hpp"
#include <iostream>
#include "restc-cpp/restc-cpp.h"

using namespace std;
using namespace restc_cpp;

/* Be sure to place your token in the line below.
 * Follow steps here to get a token:
 * https://dpp.dev/creating-a-bot-application.html
 * When you invite the bot, be sure to invite it with the
 * scopes 'bot' and 'applications.commands', e.g.
 * https://discord.com/oauth2/authorize?client_id=940762342495518720&scope=bot+applications.commands&permissions=139586816064
 */
const std::string    BOT_TOKEN = DISCORD_BOT_TOKEN;

int main()
{
	/* Create bot cluster */
	dpp::cluster bot(BOT_TOKEN);

	/* Output simple log messages to stdout */
	bot.on_log(dpp::utility::cout_logger());

	/* Handle slash command */
	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		
		if (event.command.get_command_name() == "ping") {
			command_ping(event);
		}
		});

	/* Register slash command here in on_ready */
	bot.on_ready([&bot](const dpp::ready_t& event) {
		/* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
		if (dpp::run_once<struct register_bot_commands>()) {
			
			// Register the commands
			bot.global_command_create(slashcommand_ping(bot));

		}
	});

	/* Start the bot */
	bot.start(dpp::st_wait);

	return 0;
}

#include "ping.hpp"

dpp::slashcommand slashcommand_ping(const dpp::cluster &bot) {

	dpp::slashcommand command("ping", "Ping pong!", bot.me.id);
	
	// Add the option for a user mention that isn't required
	command.add_option(dpp::command_option(dpp::co_user, "user", "The user to ping", false));
	return command;
}

void command_ping(const dpp::slashcommand_t& event) {
	// Get the user option
	dpp::command_interaction cmd_data = event.command.get_command_interaction();
	if (cmd_data.options.empty()) {
		// Reply to the command with the user mention
		event.reply(dpp::ir_channel_message_with_source, "Pong!");
	}
	else {
		dpp::user user = event.command.get_resolved_user(cmd_data.get_value<dpp::snowflake>(0));
		event.reply("Pong " + user.get_mention() + " !");
	}

}
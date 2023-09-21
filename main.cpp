#include <dpp/dpp.h>

std::string readToken(const std::string& filePath){
    std::ifstream file(filePath);
    if(file.is_open()){
        std::string token;
        std::getline(file, token);
        return token;
    } else{
        std::cerr << "File wasn't open properly." << std::endl;
    }
}

int main() {
    const std::string BOT_TOKEN = readToken("tokens.txt");

    dpp::cluster bot(BOT_TOKEN);
 
    bot.on_log(dpp::utility::cout_logger());
 
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("asdasd!");
        } else if (event.command.get_command_name() == "dupa") {
            event.reply("sraczka");
        } else if (event.command.get_command_name() == "kajtek") {
            event.reply("sztosinger");
        } else if (event.command.get_command_name() == "cs") {
            event.reply("go");
        }
    });
 
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("dupa", "twojej starej", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("kajtek", "kajtek sztosinger", bot.me.id)
            );
            bot.global_command_create(
                dpp::slashcommand("cs", "kajtek sztosinger", bot.me.id)
            );
        }
    });
 
    bot.start(dpp::st_wait);
}
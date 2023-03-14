#include "Scene.h"

Scene::Scene()
{
    music.setVolume(volume);
    music.setLoop(true);
}

Scene::~Scene()
{

}

void Scene::main_menu()
{   
    play_music("Main_Menu.wav");

    do 
    {
        clear_screen();
        display_text("Console RPG\n> Play\n> Volume\n> Text\n> Exit\n");
        enum main_menu_choice {play, volume, text, exit};

        switch (choose({"play", "volume", "text", "exit"}))
        {
        case play:
            introduction();
            return;
        case volume:
            volume_menu();
            break;
        case text:
            text_menu();
            break;
        case exit:
            return;
        default:
            break;
        }
    } while (true);
    
}

void Scene::volume_menu()
{
    do 
    {
        clear_screen();
        display_text("Current Music Volume: " + std::to_string(volume) + "\n> Increase\n> Decrease \n> Back\n");
        enum text_menu_choice {increase, decrease, back};

        switch (choose({"increase", "decrease", "back"}))
        {
        case increase:
            if (volume <= 90) 
            {
                volume += 10;
                music.setVolume(volume);
            }
            break;
        case decrease:
            
            if (volume >= 10)
            {
                volume -= 10;
                music.setVolume(volume);
            }
                
            break;
        case back:
            return;
        default:
            break;
        }
    } while (true);
}

void Scene::text_menu()
{
    do 
    {
        clear_screen();
        display_text("Choose how fast text will be displayed on the screen:\n> Slow\n> Normal\n> Fast\n> Back\n");
        enum text_menu_choice {slow, normal, fast, back};

        switch (choose({"slow", "normal", "fast", "back"}))
        {
        case slow:
            typing_speed = 75;
            break;
        case normal:
            typing_speed = 50;
            break;
        case fast:
            typing_speed = 25;
            break;
        case back:
            return;
        default:
            break;
        }
    } while (true);
    

}

void Scene::introduction()
{
    do 
    {   
        clear_screen();
        display_text("Introduction Text.\n> Begin\n> Exit\n");
        enum introduction_choice {begin, exit};

        switch (choose({"begin", "exit"}))
        {
        case begin:
            setup_player();
            if (chest() == true);
                crossroads();
            return;
        case exit:
            return;
        default:
            break;
        }
    } while (true);
}

void Scene::setup_player()
{   
    clear_screen();
    std::string player_name;
    display_text("What is your name?\n");
    std::getline(std::cin, player_name);

    enum class_choice {warrior, wizard, rogue, druid};
    do 
    {   
        clear_screen();
        display_text("What class are you?\n> Warrior\n> Wizard\n> Rogue\n> Druid\n");
        switch (choose({"warrior", "wizard", "rogue", "druid"}))
        {
        case warrior:
            player = std::make_unique<Warrior>(player_name);
            clear_screen();
            display_text("Warrior Introduction\n");
            player->add_item(std::make_unique<Longsword>());
            player->add_item(std::make_unique<ChainmailArmor>());
            press_any_key();
            inventory_menu();
            return;
        case wizard:
            player = std::make_unique<Wizard>(player_name);
            clear_screen();
            display_text("Wizard Introduction\n");
            player->add_item(std::make_unique<MagicWand>());
            player->add_item(std::make_unique<WizardRobe>());
            press_any_key();
            inventory_menu();
            return;
        case rogue:
            player = std::make_unique<Rogue>(player_name);
            clear_screen();
            display_text("Rogue Introduction\n");
            player->add_item(std::make_unique<Dagger>());
            player->add_item(std::make_unique<LeatherArmor>());
            press_any_key();
            inventory_menu();
            return;
        case druid:
            player = std::make_unique<Druid>(player_name);
            clear_screen();
            display_text("Druid Introduction\n");
            player->add_item(std::make_unique<WoodStaff>());
            player->add_item(std::make_unique<SimpleRobe>());
            press_any_key();
            inventory_menu();
            return;
        default:
            break;
        }
    } while (true);


}

void Scene::crossroads()
{   
    enum introduction_choice {north, west, east, south};
    do 
    {   
        clear_screen();
        display_text("You arrive at a crossroads, where you find three wooden signs creaking in the wind.\nThe signs read: Forest(to the north), Cave(to the west), and Village(to the east).\nWhich way do you wish to go?\n> North\n> West\n> East\n");
        
        switch (choose({"north", "west", "east", "south"}))
        {
        case north:
            current_enemy.reset(nullptr);
            current_enemy = generate_random_enemy();
            if (battle(player.get(), current_enemy.get()) == true)
            {   

                play_music("Exploring.wav");

                clear_screen();
                display_text("You enter the forest.\n");
                press_any_key();

                current_enemy.reset(nullptr);
                current_enemy = std::make_unique<GreenDragon>();
                if (battle(player.get(), current_enemy.get()) == true)
                {
                    play_music("Main_Menu.wav");
                    display_text("The End\n");
                    press_any_key();
                }
            }
            return;
        case west:
            current_enemy.reset(nullptr);
            current_enemy = generate_random_enemy();
            if (battle(player.get(), current_enemy.get()) == true)
            {   
                play_music("Exploring.wav");

                clear_screen();
                display_text("You enter the cave.\n");
                press_any_key();

                current_enemy.reset(nullptr);
                current_enemy = std::make_unique<Ogre>();
                if (battle(player.get(), current_enemy.get()) == true)
                {
                    play_music("Main_Menu.wav");
                    display_text("The End\n");
                    press_any_key();
                }
            }
            return;
        case east:
            current_enemy.reset(nullptr);
            current_enemy = generate_random_enemy();
            if(battle(player.get(), current_enemy.get()) == true)
            {   
                play_music("Exploring.wav");

                clear_screen();
                display_text("You arrive at the village.\n");
                press_any_key();
                
                current_enemy.reset(nullptr);
                current_enemy = std::make_unique<Werewolf>();
                
                if (battle(player.get(), current_enemy.get()) == true) 
                {   
                    clear_screen();
                    play_music("Main_Menu.wav");
                    display_text("The End\n");
                    press_any_key();
                }
                    
            }
            return;
        default:
            break;
        }
    } while (true);
}

bool Scene::chest()
{   
    play_music("Exploring.wav");
    enum introduction_choice {yes, no};
    do 
    {   
        clear_screen();
        display_text("You find an ornate chest in the middle of the road.\nDo you wish to open it?\n> Yes\n> No\n");
        
        switch (choose({"yes", "no"}))
        {
        case yes:
            clear_screen();
            
            current_enemy.reset(nullptr);
            current_enemy = std::make_unique<Mimic>();
            if (battle(player.get(), current_enemy.get()) == true)
            {   
                clear_screen();
                switch (player->get_type())
                {
                case warrior:
                    player->add_item(std::make_unique<MoonlightSword>());
                    break;
                case wizard:
                    player->add_item(std::make_unique<ArcaneCrystal>());
                    break;
                case rogue:
                    player->add_item(std::make_unique<ObsidianDagger>());
                    break;
                case druid:
                    player->add_item(std::make_unique<ArchtreeStaff>());
                    break;
                default:
                    break;
                }
                press_any_key();
                play_music("Exploring.wav");
                inventory_menu();
                return true;
            }
            else
                return false;
        case no:
            return true;
        default:
            break;
        }
    } while (true);

    return true;
}

std::unique_ptr<Enemy> Scene::generate_random_enemy()
{
    std::random_device random;
    std::mt19937 rng{random()};
    std::uniform_int_distribution<int> enemy{0, 2};

    enum enemies {goblin, orc, troll};

    switch (enemy(rng))
    {
    case goblin:
        return std::make_unique<Goblin>();
        break;
    case orc:
        return std::make_unique<Orc>();
        break;
    case troll:
        return std::make_unique<Troll>();
        break;
    default:
        break;
    }

    return std::make_unique<Goblin>();
}

void Scene::inventory_menu()
{   
    enum inventory_choice {character, items, advance};
    do 
    {   
        clear_screen();
        display_text("Inventory:\n> Character\n> Items\n> Continue\n");

        switch (choose({"character", "items", "continue"}))
        {
        case character:
            player->print_stats();
            break;
        case items:
            items_menu();
            break;
        case advance:
            clear_screen();
            display_text("You continue forward...");
            press_any_key();
            return;
        default:
            break;
        }
    } while (true);
}

void Scene::items_menu()
{   
    std::vector <std::string> inventory_choice;
    std::string equipped;
    do 
    {   
        clear_screen();
        display_text("Inventory:\n");

        for (int i = 0; i < player->get_inventory().size(); i++) 
        {   
            if (player->is_equipped(i) == true) 
                equipped = " (equipped)";
            display_text("> " + player->get_item(i)->get_name() + equipped + "\n");
            inventory_choice.push_back(string_to_lower(player->get_item(i)->get_name()));
            equipped = "";
        }
        
        display_text("> Back\n");
        inventory_choice.push_back("back");
        int choice = choose(inventory_choice);

        if (choice == inventory_choice.size()-1)
            return;
        else
            selected_item_menu(choice);
        
        inventory_choice.clear();
    } while (true);
}

void Scene::selected_item_menu(const int index)
{   
    std::string equipable;
    enum item_menu_choice {equip, unequip, details, back};
    
    do 
    {   
        
        if (player->is_equipped(index) == false) 
            equipable = "Equip";
        else 
        {
            equipable = "Unequip";
        }
            
        clear_screen();
        display_text(player->get_item(index)->get_name() + ":\n> " + equipable + "\n> Details\n> Back\n");
        switch (choose({"equip", "unequip", "details", "back"}))
        {
        case equip:
            if (equipable == "Equip")
                player->equip_item(player->get_item(index));
            else 
            {
                display_text("That item is already equipped.\n");
                press_any_key();
            }   
            return;
        case unequip:
            if (equipable == "Unequip")
                player->unequip_item(player->get_item(index));
            else 
            {
                display_text("That item is not currently equipped.\n");
                press_any_key();
            } 
            return;
        case details:
            player->get_item(index)->print_item_stats();
            break;
        case back:
            return;
        default:
            break;
        }
    } while (true);
}

bool Scene::battle(Player* player, Enemy* enemy)
{   
    play_music("BattleFinal.wav");

    clear_screen();
    display_text(enemy->get_encounter_description());
    press_any_key();
    do 
    {   

        clear_screen();
        enemy->take_damage(player->attack(), player->get_accuracy());
        if (enemy->get_health() < 1) 
        {   
            display_text("You have defeated the " + string_to_lower(enemy->get_name()) + ".\n");
            press_any_key();
            return true;
        }
        
        press_any_key();

        player->take_damage(enemy->attack(), enemy->get_accuracy());
        if (player->get_health() < 1) 
        {   
            clear_screen();
            play_music("Main_Menu.wav");
            display_text("You have been defeated by the " + string_to_lower(enemy->get_name()) + ".\nGame Over\n");
            press_any_key();
            return false;
        }   
        press_any_key();

    } while (true);  

}

void Scene::play_music(const std::string music_file)
{
    music.stop();
    music.openFromFile(music_file);
    music.play();
}
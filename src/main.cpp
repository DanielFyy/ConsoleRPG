#include "Scene.h"

int main(int argc, char const *argv[])
{   

    
    //scene is heap instantiated for debubgging 
    //for the destructor to be called before displaying created and destroyed objects
    Scene* scene = new Scene;
    scene->main_menu();
    delete scene;
    
    std::cout << "Created objects: " << created << "\n";
    std::cout << "Destroyed objects: " << destroyed << "\n";

    return 0;
}

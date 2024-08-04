#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::cerr;
class Button{
    public:
        virtual void render(void)=0;
        explicit Button(){
            std::cout<<"Button Constructor\n";
        }
        virtual ~Button(){
            std::cout<<"Button Destructor\n";
        }
};
class LightButton: public Button{
    public:
        void render(void) override final{
            std::cout<<"Rendering light button\n";
        }
        explicit LightButton(){
            std::cout<<"LightButton Constructor\n";
        }
        virtual ~LightButton(){
            std::cout<<"LightButton Destructor\n";
        }
};
class DarkButton: public Button{
    public:
        void render(void)override final{
            std::cout<<"Rendering Dark button\n";
        }
        explicit DarkButton(){
            std::cout<<"DarkButton Constructor\n";
        }
        virtual ~DarkButton(){
            std::cout<<"DarkButton Destructor\n";
        }
};
class CheckBox{
    public:
        virtual void render(void)=0;
        explicit CheckBox(){
            std::cout<<"CheckBox Constructor\n";
        }
        virtual ~CheckBox(){
            std::cout<<"CheckBox Destructor\n";
        }
};
class LightCheckBox: public CheckBox{
    public:
        void render(void)override final{
            std::cout<<"Rendering Light Check Box\n";
        }
        explicit LightCheckBox(){
            std::cout<<"LightCheckBox Constructor\n";
        }
        virtual ~LightCheckBox(){
            std::cout<<"LightCheckBox Destructor\n";
        }
};
class DarkCheckBox: public CheckBox{
    public:
        void render(void)override final{
            std::cout<<"Rendering Dark Check Box\n";
        }
        explicit DarkCheckBox(){
            std::cout<<"DarkCheckBox Constructor\n";
        }
        virtual ~DarkCheckBox(){
            std::cout<<"DarkCheckBox Destructor\n";
        }
};
class ThemeFactory{
    public:
        virtual Button* CreateButton(void)=0;
        virtual CheckBox* CreateCheckBox(void)=0;
        explicit ThemeFactory(){
            std::cout<<"ThemeFactory Constructor\n";
        }
        virtual ~ThemeFactory(){
            std::cout<<"ThemeFactory Destructor\n";
        }
};
class LightThemeFactory: public ThemeFactory{
    public:
        Button* CreateButton(void)override final{
            return new LightButton();
        }
        CheckBox* CreateCheckBox(void)override final{
            return new LightCheckBox();
        }
        explicit LightThemeFactory(){
            std::cout<<"LightThemeFactory Constructor\n";
        }
        virtual ~LightThemeFactory(){
            std::cout<<"LightThemeFactory Destructor\n";
        }
};
class DarkThemeFactory: public ThemeFactory{
    public:
        Button* CreateButton(void)override final{
            return new DarkButton();
        }
        CheckBox* CreateCheckBox(void)override final{
            return new DarkCheckBox();
        }
        explicit DarkThemeFactory(){
            std::cout<<"DarkThemeFactory Constructor\n";
        }
        virtual ~DarkThemeFactory(){
            std::cout<<"DarkThemeFactory Destructor\n";
        }
};

int main(int argc, char* argv[], char** env){
    // Create light theme components
    ThemeFactory* lightFactory = new LightThemeFactory();
    Button* lightButton = lightFactory->CreateButton();
    CheckBox* lightCheckBox = lightFactory->CreateCheckBox();
    lightButton->render();
    lightCheckBox->render();

    // Create dark theme component
    ThemeFactory* darkFactory = new LightThemeFactory();
    Button* darkButton = darkFactory->CreateButton();
    CheckBox* darkCheckBox = darkFactory->CreateCheckBox();
    darkButton->render();
    darkCheckBox->render();

    delete lightFactory;
    delete lightButton;
    delete lightCheckBox;
    delete darkFactory;
    delete darkButton;
    delete darkCheckBox;
    return 0;
}
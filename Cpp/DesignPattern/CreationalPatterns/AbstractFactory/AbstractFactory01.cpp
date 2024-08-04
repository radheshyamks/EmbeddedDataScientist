#include <iostream>
using namespace std;
// Abstract product interfaces
class Button {
public:
    virtual void render() = 0;
};

// Concrete product classes for light theme
class LightButton : public Button {
public:
    void render() override {
        cout << "Rendering light button" << endl;
    }
};

// Concrete product classes for dark theme
class DarkButton : public Button {
public:
    void render() override {
        cout << "Rendering dark button" << endl;
    }
};

class Checkbox {
public:
    virtual void render() = 0;
};

class LightCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering light checkbox" << endl;
    }
};


class DarkCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering dark checkbox" << endl;
    }
};
// Abstract factory interface
class ThemeFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
};

// Concrete factory for light theme
class LightThemeFactory : public ThemeFactory {
public:
    Button* createButton() override {
        return new LightButton();
    }

    Checkbox* createCheckbox() override {
        return new LightCheckbox();
    }
};

// Concrete factory for dark theme
class DarkThemeFactory : public ThemeFactory {
public:
    Button* createButton() override {
        return new DarkButton();
    }

    Checkbox* createCheckbox() override {
        return new DarkCheckbox();
    }
};
// Client code
int main() {
    // Create light theme components
    ThemeFactory* lightFactory = new LightThemeFactory();
    Button* lightButton = lightFactory->createButton();
    Checkbox* lightCheckbox = lightFactory->createCheckbox();
    lightButton->render();
    lightCheckbox->render();

    // Create dark theme components
    ThemeFactory* darkFactory = new DarkThemeFactory();
    Button* darkButton = darkFactory->createButton();
    Checkbox* darkCheckbox = darkFactory->createCheckbox();
    darkButton->render();
    darkCheckbox->render();

    // Clean up
    delete lightButton;
    delete lightCheckbox;
    delete darkButton;
    delete darkCheckbox;
    delete lightFactory;
    delete darkFactory;

    return 0;
}
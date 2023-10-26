//
// Created by Кирилл Деменев on 26.10.2023.
//

#ifndef LAB1_IWINDOW_H
#define LAB1_IWINDOW_H




class IWindow {
public:
    virtual void open();
    virtual void print_window();

    virtual int getChoice();
    virtual void setChoice(int newChoice);

    int startx;
    int starty;
private:
    int n_choices;
    std::string menu_choices[3];
    int choice;
    WINDOW* Menu;
};


#endif //LAB1_IWINDOW_H

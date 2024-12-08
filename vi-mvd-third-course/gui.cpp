
class InputWindow : public Fl_Window {
  public:
    InputWindow(int w, int h, const char* t);
    ~InputWindow();
 
    Fl_Window          *window;
    Fl_Input           *input_surname;
    Fl_Input           *input_name;
    Fl_Button          *input_enter;
    Fl_Button          *input_cancel;
    char               search[256];
};



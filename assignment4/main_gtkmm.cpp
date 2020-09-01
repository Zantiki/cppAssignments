#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry entry_first;
  Gtk::Entry entry_second;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    button.set_label("Join Names");

    vbox.pack_start(entry_first);
    vbox.pack_start(entry_second);
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets
    button.set_sensitive (false);

    entry_first.signal_changed().connect([this]() {
      //label.set_text("Entry now contains: " + entry_first.get_text());
        if (label.get_text() != ""){
            label.set_text("");
        }
        if(entry_second.get_text() == "" ){
            button.set_sensitive (false);
        }else{
            button.set_sensitive (true);
        }
    });

      entry_second.signal_changed().connect([this]() {

          if (label.get_text() != ""){
              label.set_text("");
          }

          if(entry_second.get_text() == "" ){
              button.set_sensitive (false);
          }else{
              button.set_sensitive (true);
          }

      });

    entry_first.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });

    button.signal_clicked().connect([this]() {
      label.set_text(entry_first.get_text() + " " + entry_second.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  // window.set_label("Full-name joiner");
  gtk_main.run(window);
}

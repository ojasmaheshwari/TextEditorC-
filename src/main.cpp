#include "gtkmm/application.h"
#include "gtkmm/builder.h"
#include "gtkmm/window.h"
#include <gtkmm-3.0/gtkmm.h>

int main(int argc, char **argv) {
  auto app = Gtk::Application::create("com.epicman.texteditor");
  auto builder = Gtk::Builder::create_from_file("TextEditor.glade");
  Gtk::Window *window;
  builder->get_widget("window", window);
  app->run(*window);
}

#include "glibmm/refptr.h"
#include "gtkmm/builder.h"
#include "gtkmm/label.h"
#include "gtkmm/textbuffer.h"
#include "gtkmm/textview.h"
#include "gtkmm/window.h"
#include "include/globals.h"
#include "include/menubar.h"

Glib::RefPtr<Gtk::Application> app;
Glib::RefPtr<Gtk::Builder> builder;
Gtk::Window *window;
Gtk::ImageMenuItem *file_open_menu_item, *file_save_menu_item;
Gtk::TextView *editor;
Glib::RefPtr<Gtk::TextBuffer> code_buffer;
Gtk::Label *statusbar;
std::string active_filepath;

int main(int argc, char **argv) {
  app = Gtk::Application::create("com.epicman.texteditor");
  builder = Gtk::Builder::create_from_file("TextEditor.glade");
  builder->get_widget("window", window);
  builder->get_widget("code_view", editor);
  builder->get_widget("statusbar", statusbar);
  code_buffer = Gtk::TextBuffer::create();
  editor->set_buffer(code_buffer);

  setup_menubar();

  app->run(*window);
}

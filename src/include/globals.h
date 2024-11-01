#pragma once

#include "glibmm/refptr.h"
#include "gtkmm/application.h"
#include "gtkmm/builder.h"
#include "gtkmm/imagemenuitem.h"
#include "gtkmm/label.h"
#include "gtkmm/textbuffer.h"
#include "gtkmm/window.h"
#include <gtkmm-3.0/gtkmm.h>

extern Glib::RefPtr<Gtk::Application> app;
extern Glib::RefPtr<Gtk::Builder> builder;
extern Gtk::Window *window;
extern Gtk::ImageMenuItem *file_open_menu_item, *file_save_menu_item;
extern Gtk::TextView *editor;
extern Glib::RefPtr<Gtk::TextBuffer> code_buffer;
extern Gtk::Label *statusbar;
extern std::string active_filepath;

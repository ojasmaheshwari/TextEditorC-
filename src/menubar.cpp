#include "include/menubar.h"
#include "gtkmm/filechooser.h"
#include "gtkmm/filechoosernative.h"
#include "include/globals.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

void save_file() {
  std::string data = code_buffer->get_text();
  std::ofstream file(active_filepath);

  std::cout << active_filepath << '\n';

  file << data;

  file.close();
}

void open_file_browser() {
  auto dialog = Gtk::FileChooserNative::create(
      "Choose a file", *window,
      Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN, "Accept", "Cancel");
  dialog->run();
  auto file = dialog->get_file();
  if (file)
    load_from_file_into_editor(file->get_path());
}

void load_from_file_into_editor(const std::string &file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    std::cout << "Some error occured while opening the file\n";
    return;
  }
  std::string data, line;
  while (std::getline(file, line)) {
    data += line + '\n';
  }

  code_buffer->set_text(data);
  statusbar->set_text("Current file: " + file_path);
  active_filepath = file_path;

  file.close();
}

void setup_file_open() {
  builder->get_widget("menu-item-file-open", file_open_menu_item);
  file_open_menu_item->signal_activate().connect([]() { open_file_browser(); });
}

void setup_file_save() {
  builder->get_widget("menu-item-file-save", file_save_menu_item);
  file_save_menu_item->signal_activate().connect([]() { save_file(); });
}

void setup_menubar() {
  setup_file_open();
  setup_file_save();
}

### install:

1. clone

        git clone https://github.com/xordone/crkbd-keymap 1pxl
2. symlink to qmk/keyboards/crkbd/keymaps/
3. add secret.c with text like
        
        char td1_string[] = "";
4. compile firmware
        
        qmk compile -kb crkbd -km 1pxl

5. flash your corne
6. enjoy

### layout

[keyboard-layout-editor](http://www.keyboard-layout-editor.com/#/gists/75d5858872acfa366811df40c6937df0)
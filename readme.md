### install:

1. symlink to qmk/keyboards/crkbd/keymaps/
2. add secret.c with text like
        
        char td1_string[] = "";
3. compile firmware
        
        qmk compile -kb crkbd -km 1pxl

4. flash your corne
5. enjoy
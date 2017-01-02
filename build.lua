tool { name = 'bltc',
   projects = {
      app {
         icon = 'icon/bengine-warm.ico',
         src = {
            'src/*.cpp'
         },
         libs = {
            'core',
            'core-id-with-names',
            'util',
            'cli',
            'ctable',
            'blt'
         }
      }
   }
}

#include "Filter.h"


//Coloca todos os componentes de cor do pixel com o valor de Azul

class BlueSelectionChannel : public Filter
{
public:

    void apply(Bitmap& bmp);

};


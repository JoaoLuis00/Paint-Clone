#ifndef REDSELECTIONCHANNEL_H
#define REDSELECTIONCHANNEL_H

#include "Filter.h"

//Filtro de sele��o de canal vermelho -> todos as componentes azul e verde 

class RedSelectionChannel :  public Filter
{
public:

    void apply(Bitmap& bmp);

};
#endif

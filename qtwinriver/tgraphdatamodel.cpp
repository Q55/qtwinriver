#include "tgraphdatamodel.h"

TGraphDataModel::TGraphDataModel()
{
    this->record_num = raw_data->GetDataModel()->rowCount();
}


#ifndef TGRAPHDATAMODEL_H
#define TGRAPHDATAMODEL_H
#include "rawdatafromdb.h"

extern RawDataFromDB *raw_data;

// Test Graph Data Model
class TGraphDataModel
{
public:
    TGraphDataModel();
    int GetRecordNum() {return record_num; }

private:
    int record_num;
    double complex_result_calc_by_algo; // TODO: this result are calc by a new thread.

};

#endif // TGRAPHDATAMODEL_H

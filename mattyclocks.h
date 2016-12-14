#ifndef MATTYCLOCKS_H
#define MATTYCLOCKS_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QLCDNumber>

class MattyClocks : public QLCDNumber
{
Q_OBJECT
public:
    MattyClocks(QWidget *parent = 0);
    ~MattyClocks();

    private slots:
    void showTime();
};


#endif // MATTYCLOCKS_H

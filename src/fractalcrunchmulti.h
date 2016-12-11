/*
This file is part of geomandel. An artful fractal generator
Copyright © 2015, 2016 Christian Rapp

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FRACTALCRUNCHMULTI_H
#define FRACTALCRUNCHMULTI_H

#include <thread>
#include "ctpl_stl.h"

#include "global.h"
#include "fractalcruncher.h"

template <class T> class Fractalcrunchmulti : public Fractalcruncher<T>
{
public:
    Fractalcrunchmulti(constants::fracbuff &buff,
                      const std::shared_ptr<FractalParameters> &params);
    virtual ~Fractalcrunchmulti();

    void fill_buffer();

private:
    /* data */
};

#endif /* ifndef FRACTALCRUNCHMULTI_H */

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

#ifndef FRACTALCRUNCHER_MOCK_H
#define FRACTALCRUNCHER_MOCK_H

#include <tuple>

#include "fractalcruncher.h"

class FractalcruncherMock : public Fractalcruncher
{
public:
    FractalcruncherMock(constants::fracbuff &buff,
                       const std::shared_ptr<FractalParameters> &params);
    virtual ~FractalcruncherMock();

    void fill_buffer();
    std::tuple<unsigned int, double, double> test_cruncher(
        double real, double ima, unsigned int bailout) const;
    constants::Iterations test_iterfactory(unsigned int its, double z_real,
                                           double z_ima) const;

private:
    /* data */
};

#endif /* ifndef FRACTALCRUNCHER_MOCK_H */

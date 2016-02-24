/*
This file is part of geomandel. Mandelbrot Set infused by GeoTIFF
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

#ifndef IMAGEGREY_H
#define IMAGEGREY_H

#include "global.h"
#include "image_pnm.h"

class Imagegrey : public ImagePNM
{
public:
    Imagegrey(const constants::mandelbuff &buff,
              const std::shared_ptr<MandelParameters> &params,
              std::tuple<int, int, int> rgb_base,
              std::tuple<double, double, double> rgb_freq);
    virtual ~Imagegrey();

private:
    /* data */

    std::tuple<int, int, int> rgb_base;
    std::tuple<double, double, double> rgb_freq;

    void out_format_write(std::ofstream &img, const constants::Iterations &data);
};

#endif /* ifndef IMAGEGREY_H */

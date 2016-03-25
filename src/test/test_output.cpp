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

#include "catch.hpp"

#include "buffwriter_mock.h"

#include <type_traits>

/**
 * @brief Primitives to string conversion
 *
 * @tparam T Type of primitive to convert
 * @param value
 *
 * @return String
 *
 * @details
 * Converts primitive data types to strings using std::to_string. Additionally
 * trailing '0' will be deleted.
 */
template <typename T>
std::string primitive_to_string(T value)
{
    std::string val_to_string = std::to_string(value);
    if (std::is_same<double, T>::value || std::is_same<float, T>::value) {
        val_to_string.erase(val_to_string.find_last_not_of('0') + 1,
                            std::string::npos);
        // check if last char is a point
        if (val_to_string.back() == '.') {
            val_to_string = val_to_string.substr(0, val_to_string.size() - 1);
        }
    }
    return val_to_string;
}

TEST_CASE("Filename Patterns", "[output]")
{
    // some sane values for supported filename patterns
    unsigned int bailout = 2048;  // %b
    unsigned int xrange = 1024;   // %w
    unsigned int yrange = 768;    // %h
    unsigned int zoom = 0;        // %z
    unsigned int cores = 4;       // %c
    double xcoord = 323;          // %x
    double ycoord = 233;          // %y
    double z_real_min = -2.5;     // %Zr
    double z_real_max = 1.0;      // %ZR
    double z_ima_min = -1.5;      // %Zi
    double z_ima_max = 1.5;       // %ZI

    constants::fracbuff b;
    BuffwriterMock bmock(b);

    SECTION("Simple filename with three patterns")
    {
        std::string pattern = "mandi_%wx%h_%z.png";
        std::string filename = bmock.test_filename_patterns(
            pattern, bailout, xrange, yrange, zoom, cores, xcoord, ycoord,
            z_real_min, z_real_max, z_ima_min, z_ima_max);
        REQUIRE(filename ==
                "mandi_" + primitive_to_string(xrange) + "x" +
                    primitive_to_string(yrange) + "_" +
                    primitive_to_string(zoom) + ".png");
    }

    SECTION("Special case where .0 floats should be displayed as integers")
    {
        std::string pattern = "mandeltest_[%x-%y]";
        xcoord = 280.0;
        ycoord = 178.0;
        std::string filename = bmock.test_filename_patterns(
            std::move(pattern), bailout, xrange, yrange, zoom, cores, xcoord,
            ycoord, z_real_min, z_real_max, z_ima_min, z_ima_max);
        REQUIRE(filename ==
                "mandeltest_[" + primitive_to_string(xcoord) + "-" +
                    primitive_to_string(ycoord) + "]");
    }
    SECTION("Complex file name with all patterns")
    {
        // %a is a fake pattern
        std::string pattern =
            "mandeltest_%a_%wx%h_b%b_m%c_[%x, %y --> %z]_(%Zr, %Zi)->(%ZR, %ZI)";
        std::string filename = bmock.test_filename_patterns(
            std::move(pattern), bailout, xrange, yrange, zoom, cores, xcoord,
            ycoord, z_real_min, z_real_max, z_ima_min, z_ima_max);
        REQUIRE(filename ==
                "mandeltest_%a_" + primitive_to_string(xrange) + "x" +
                    primitive_to_string(yrange) + "_b" +
                    primitive_to_string(bailout) + "_m" +
                    primitive_to_string(cores) + "_[" +
                    primitive_to_string(xcoord) + ", " +
                    primitive_to_string(ycoord) + " --> " +
                    primitive_to_string(zoom) + "]_(" +
                    primitive_to_string(z_real_min) + ", " +
                    primitive_to_string(z_ima_min) + ")->(" +
                    primitive_to_string(z_real_max) + ", " +
                    primitive_to_string(z_ima_max) + ")");
    }
}

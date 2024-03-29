//
//  Created by Junaid Afzal on 22/11/2019.
//  Edited by Jedidiah Paterson on 24/03/2020
//  Copyright © 2019 Junaid Afzal. All rights reserved.
//
//  This source files contains all the test code for
//  the object the sub objects of Cell - Tetrahedron,
//  Pyramid, and Hexahedron - and demonstrates all the
//  functionality of the object

#include "Material.h"
#include "Vectors.h"
#include "Cell.hpp"
#include "Testing_File_Functions.h"

int main()
{
    unsigned int Testing_For_Error = 0;
    unsigned int Error = 0;
    Material Empty_To_Compare_to;
    std::cout << "------------------------------Cell.hpp Test Code------------------------------" << std::endl;

    Cell Test_Blank;
    // When a Cell is created it is created a vector array of Vectors, "Vertices"
    // a vector array of the order in which those Vertices are ordered, "VerticesOrder"
    // and the Material that make up the Cell "theMaterial".

    // Becuase we called the Blank constructor the two vector arrays will be empty
    // and have a size of "0" and the Material will be constructed using the Material's
    // class blank constuctor.
    Error = Testing(Test_Blank, Empty_To_Compare_to);

    Material Copper(5, 8944.0, "B87333", "Copper");
    Test_Blank.Set_Material(Copper);

    Testing_For_Error = Testing(Test_Blank.Get_Material(), Copper);

    if (Testing_For_Error == 0)
        std::cout << "Set/Get Material Functions Works Properly" << std::endl;
    else
    {
        std::cout << "Set/Get Material Functions Do Not Working Properly" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    Test_Blank.Set_Material(Empty_To_Compare_to);

    // Now we test the Cells Set/Get Functions
    // In Order to do this we create so Vectors
    // and then put them into a vector

    Vectors aVectors(-5.0,-5.0,0.0);
    Vectors bVectors( 5.0,-5.0,0.0);
    Vectors cVectors( 5.0, 5.0,0.0);
    Vectors dVectors(-5.0, 5.0,0.0);

    std::vector<Vectors> SquareVertices;
    SquareVertices.push_back(aVectors);
    SquareVertices.push_back(bVectors);
    SquareVertices.push_back(cVectors);
    SquareVertices.push_back(dVectors);
    Test_Blank.Set_Vertices(SquareVertices);

    //Also need to Set the oder at which the Vectors should be arranged
    std::vector<int> aRelaventOrder;// = {3, 2, 1, 0};
    aRelaventOrder.push_back(3);
    aRelaventOrder.push_back(2);
    aRelaventOrder.push_back(1);
    aRelaventOrder.push_back(0);
    Test_Blank.Set_Vertices_Order(aRelaventOrder);
    Testing_For_Error = Testing(Test_Blank, SquareVertices, aRelaventOrder, Empty_To_Compare_to);

    if (Testing_For_Error == 0)
        std::cout << "Set Vertices Order, Set Vertices, and their Get Functions Works Properly" << std::endl;
    else
    {
        std::cout << "Set Vertices Order, Set Vertices, and their Get Functions Do Not Working Properly" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    // Now we test get volume/weight/Centre of Gravity
    // Get olume/weight/Centre of Gravity should return "-1" since they
    // are only valid for subclasses of the Cell class
    // NOTE* They all should return an ERROR code

    Testing_For_Error = Testing(Test_Blank.Get_Volume(), -1.0);

    if (Testing_For_Error == 0)
        std::cout << "Get Volume Function Works Properly" << std::endl;
    else
    {
        std::cout << "Get Volume Function Does Not Working Properly" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    Testing_For_Error = Testing(Test_Blank.Get_Weight(), -1.0);

    if (Testing_For_Error == 0)
        std::cout << "Get Weight Function Works Properly" << std::endl;
    else
    {
        std::cout << "Get Weight Function Does Not Working Properly" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    Vectors Center_Of_Cell_Test_Blank(-1.0, -1.0, -1.0); // This is actual and error code
    Testing_For_Error = Testing(Test_Blank.Get_Centre_Of_Gravity() , Center_Of_Cell_Test_Blank);

    if (Testing_For_Error == 0)
        std::cout << "Get Centre Of Gravity Function Works Properly" << std::endl;
    else
    {
        std::cout << "Get Centre Of Gravity Function Does Not Working Properly" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    // The next function to test is the Rotate the number of possible rotations
    // around the x, y, and Z axis from 0-360 degrees is near infinate. We will
    // only test 3 rotations about the x, y, and z axis at 90 degrees for each
    // rotation.

    Vectors Center_For_Rotation(0.0, 0.0, 0.0);
    Cell Rotated;
    Rotated.Set_Vertices_Order(aRelaventOrder);

    Vectors eVectors(0.0,-5.0, 5.0);
    Vectors fVectors(0.0,-5.0,-5.0);
    Vectors gVectors(0.0, 5.0,-5.0);
    Vectors hVectors(0.0, 5.0, 5.0);

    std::vector<Vectors> SquareVertices_Rotated;
    SquareVertices_Rotated.push_back(eVectors);
    SquareVertices_Rotated.push_back(fVectors);
    SquareVertices_Rotated.push_back(gVectors);
    SquareVertices_Rotated.push_back(hVectors);
    Rotated.Set_Vertices(SquareVertices_Rotated);
    Test_Blank.Rotate(90.0, 'y', Center_For_Rotation);

    Testing_For_Error = Testing(Test_Blank, Rotated);

    if (Testing_For_Error == 0)
        std::cout << "Rotate Function Works Properly For Y-Axis Rotation" << std::endl;
    else
    {
        std::cout << "Rotate Function Does Not Working Properly For Y-Axis Rotation" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    eVectors.SetVector( 5.0, 0.0, 5.0);
    fVectors.SetVector( 5.0, 0.0,-5.0);
    gVectors.SetVector(-5.0, 0.0,-5.0);
    hVectors.SetVector(-5.0, 0.0, 5.0);

    SquareVertices_Rotated.clear(); // clear old array to ensure only new vectors are present
    SquareVertices_Rotated.push_back(eVectors);
    SquareVertices_Rotated.push_back(fVectors);
    SquareVertices_Rotated.push_back(gVectors);
    SquareVertices_Rotated.push_back(hVectors);
    Rotated.Set_Vertices(SquareVertices_Rotated);

    Test_Blank.Rotate(90.0, 'z', Center_For_Rotation);
    Testing_For_Error = Testing(Test_Blank, Rotated);

    if (Testing_For_Error == 0)
        std::cout << "Rotate Function Works Properly For Z-Axis Rotation" << std::endl;
    else
    {
        std::cout << "Rotate Function Does Not Working Properly For Z-Axis Rotation" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    eVectors.SetVector( 5.0,-5.0, 0.0);
    fVectors.SetVector( 5.0, 5.0, 0.0);
    gVectors.SetVector(-5.0, 5.0, 0.0);
    hVectors.SetVector(-5.0,-5.0, 0.0);

    SquareVertices_Rotated.clear(); // clear old array to ensure only new vectors are present
    SquareVertices_Rotated.push_back(eVectors);
    SquareVertices_Rotated.push_back(fVectors);
    SquareVertices_Rotated.push_back(gVectors);
    SquareVertices_Rotated.push_back(hVectors);
    Rotated.Set_Vertices(SquareVertices_Rotated);

    Test_Blank.Rotate(90.0, 'x', Center_For_Rotation);
    Testing_For_Error = Testing(Test_Blank, Rotated);

    if (Testing_For_Error == 0)
        std::cout << "Rotate Function Works Properly For X-Axis Rotation" << std::endl;
    else
    {
        std::cout << "Rotate Function Does Not Working Properly For X-Axis Rotation" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    // Now to test the operator=  we will create a new cell
    // it will be initlized to empty as previously seen
    // then we will set Test_Blank = to the empty New_Blank_cell and test its operation

    Cell New_Blank_cell;
    Test_Blank = New_Blank_cell;

    Testing_For_Error = Testing(Test_Blank, New_Blank_cell);

    if (Testing_For_Error == 0)
        std::cout << "Operator= Function Works Properly" << std::endl;
    else
    {
        std::cout << "Operator= Function Did Not Work Properly" << std::endl;
        Error = 1;
        Testing_For_Error = 0;
    }

    std::cout << "************************" << std::endl;
    if (Error == 0 )
        std::cout << "Cell Test: Successful" << std::endl;
    else
        std::cout << "Cell Test: Failure" << std::endl;
    std::cout << "************************" << std::endl;

    std::cout << "------------------------------Tetrahedron Test Code------------------------------" << std::endl;

    unsigned int Error_Tetrahedron = 0;

    Tetrahedron Empty_Tetra;
    if (Testing(Empty_Tetra, Empty_To_Compare_to) == 1 )
        Error_Tetrahedron = 1;

    // Now to test a fully constructed Cell
    Vectors iVectors( 0.0,  0.0,  0.0);
    Vectors jVectors( 5.0,  0.0,  1.0);
    Vectors kVectors( 2.5,  3.2, -1.25);
    Vectors lVectors(-1.9, -0.5, -2.23);
    std::vector<Vectors> Vertices_Of_Tetra;
    Vertices_Of_Tetra.push_back(iVectors);
    Vertices_Of_Tetra.push_back(jVectors);
    Vertices_Of_Tetra.push_back(kVectors);
    Vertices_Of_Tetra.push_back(lVectors);
    std::vector<int> Vertices_Of_Tetra_Order;
    Vertices_Of_Tetra_Order.push_back(0);
    Vertices_Of_Tetra_Order.push_back(1);
    Vertices_Of_Tetra_Order.push_back(2);
    Vertices_Of_Tetra_Order.push_back(3);
    Material Gold(0, 19300.0, "D4AF37", "Gold" );

    Tetrahedron Gold_Nugget(Vertices_Of_Tetra, Vertices_Of_Tetra_Order, Gold);
    Testing_For_Error = Testing(Gold_Nugget, Vertices_Of_Tetra, Vertices_Of_Tetra_Order, Gold);

    if (Testing_For_Error == 0)
        std::cout << "Tetrahedron Set With Constructor Properly" << std::endl;
    else
    {
        std::cout << "Tetrahedron Not Set With Constructor Properly" << std::endl;
        Error_Tetrahedron = 1;
        Testing_For_Error = 0;
    }

    Vectors Center_Of_Gold_Nugget(1.4, 0.675, -0.62);
    if (Testing(Gold_Nugget, 5.6625, 109286.25, Center_Of_Gold_Nugget) == 1)
        Error_Tetrahedron = 1;

    std::cout << "************************" << std::endl;
    if (Error_Tetrahedron == 0 )
        std::cout << "Tetrahedron Test: Successful" << std::endl;
    else
        std::cout << "Tetrahedron Test: Failure" << std::endl;
    std::cout << "************************" << std::endl;

    std::cout << "------------------------------Pyramid Test Code------------------------------" << std::endl;

    unsigned int Error_Pyramid = 0;

    Pyramid Empty_Pryamid;
    if (Testing(Empty_Pryamid, Empty_To_Compare_to) == 1)
        Error_Pyramid = 1;

    Vectors mVectors(-5.0,-5.0, 0.0);
    Vectors nVectors( 5.0,-5.0, 0.0);
    Vectors oVectors( 5.0, 5.0, 0.0);
    Vectors pVectors(-5.0, 5.0, 0.0);
    Vectors qVectors( 0.0, 0.0, 5.0);
    std::vector<Vectors> Vertices_Of_Pyramid;
    Vertices_Of_Pyramid.push_back(mVectors);
    Vertices_Of_Pyramid.push_back(nVectors);
    Vertices_Of_Pyramid.push_back(oVectors);
    Vertices_Of_Pyramid.push_back(pVectors);
    Vertices_Of_Pyramid.push_back(qVectors);
    std::vector<int> Vertices_Of_Pryamid_Order;
    Vertices_Of_Pryamid_Order.push_back(0);
    Vertices_Of_Pryamid_Order.push_back(1);
    Vertices_Of_Pryamid_Order.push_back(2);
    Vertices_Of_Pryamid_Order.push_back(3);
    Vertices_Of_Pryamid_Order.push_back(4);
    Material LimeStone(1, 2711.0, "DFD8BF", "Limestone" );

    Pyramid Here_Lays_A_Pharaoh(Vertices_Of_Pyramid, Vertices_Of_Pryamid_Order, LimeStone);
    Testing_For_Error = Testing(Here_Lays_A_Pharaoh, Vertices_Of_Pyramid, Vertices_Of_Pryamid_Order, LimeStone);

     if (Testing_For_Error == 0)
         std::cout << "Pyramid Set With Constructor Properly" << std::endl;
     else
     {
         std::cout << "Pyramid Not Set With Constructor Properly" << std::endl;
         Error_Pyramid = 1;
         Testing_For_Error = 0;
     }
    Vectors Center_Of_The_Tomb(0.0, 0.0, 1.25);
    if (Testing(Here_Lays_A_Pharaoh, (500.0/3.0) , ((500.0/3.0)*(2711.0)) , Center_Of_The_Tomb) == 1)
        Error_Pyramid = 1;

    std::cout << "************************" << std::endl;
    if (Error_Pyramid == 0 )
        std::cout << "Pyramid Test: Successful" << std::endl;
    else
        std::cout << "Pyramid Test: Failure" << std::endl;
    std::cout << "************************" << std::endl;

    std::cout << "------------------------------Hexahedron Test Code------------------------------" << std::endl;

    unsigned int Error_Hexahedron = 0;

    Hexahedron Empty_Hexahedron;
    if (Testing(Empty_Hexahedron, Empty_To_Compare_to) == 1)
        Error_Hexahedron = 1;

    Vectors rVectors(-1.5,-2.5,-1.5);
    Vectors sVectors( 1.5,-2.5,-1.5);
    Vectors tVectors( 1.5, 2.5,-1.5);
    Vectors uVectors(-1.5, 2.5,-1.5);
    Vectors vVectors(-2.5,-2.5, 2.5);
    Vectors wVectors( 2.5,-2.5, 2.5);
    Vectors xVectors( 2.5, 2.5, 2.5);
    Vectors yVectors(-2.5, 2.5, 2.5);
    std::vector<Vectors> Vertices_Of_Hexahedron;
    Vertices_Of_Hexahedron.push_back(rVectors);
    Vertices_Of_Hexahedron.push_back(sVectors);
    Vertices_Of_Hexahedron.push_back(tVectors);
    Vertices_Of_Hexahedron.push_back(uVectors);
    Vertices_Of_Hexahedron.push_back(vVectors);
    Vertices_Of_Hexahedron.push_back(wVectors);
    Vertices_Of_Hexahedron.push_back(xVectors);
    Vertices_Of_Hexahedron.push_back(yVectors);
    std::vector<int> Vertices_Of_Hexahedron_Order;
    Vertices_Of_Hexahedron_Order.push_back(0);
    Vertices_Of_Hexahedron_Order.push_back(1);
    Vertices_Of_Hexahedron_Order.push_back(2);
    Vertices_Of_Hexahedron_Order.push_back(3);
    Vertices_Of_Hexahedron_Order.push_back(4);
    Vertices_Of_Hexahedron_Order.push_back(5);
    Vertices_Of_Hexahedron_Order.push_back(6);
    Vertices_Of_Hexahedron_Order.push_back(7);
    Material Diamond(2, 3514.0, "B9F2FF", "Diamond" );

    Hexahedron Dimaond_Stone(Vertices_Of_Hexahedron, Vertices_Of_Hexahedron_Order, Diamond);
    Testing_For_Error = Testing(Dimaond_Stone, Vertices_Of_Hexahedron, Vertices_Of_Hexahedron_Order, Diamond);
    
    if (Testing_For_Error == 0)
        std::cout << "Hexahedron Set With Constructor Properly" << std::endl;
    else
    {
        std::cout << "Hexahedron Not Set With Constructor Properly" << std::endl;
        Error_Hexahedron = 1;
        Testing_For_Error = 0;
    }

    Vectors Center_Of_The_Diamond(0.0, 0.0, (2.0/3.0) );
    if (Testing(Dimaond_Stone, 80.0, 281120.0, Center_Of_The_Diamond) == 1)
        Error_Hexahedron = 1;

    std::cout << "************************" << std::endl;
    if (Error_Hexahedron == 0 )
        std::cout << "Hexahedron Test: Successful" << std::endl;
    else
        std::cout << "Hexahedron Test: Failure" << std::endl;
    std::cout << "************************" << std::endl;

    std::cout << "************************" << std::endl;
    if ( (Error == 0 )&&(Error_Tetrahedron == 0)&&(Error_Pyramid == 0)&&(Error_Hexahedron == 0) )
        std::cout << "End of Test: Successful" << std::endl;
    else
        std::cout << "End of Test: Failure" << std::endl;
    std::cout << "************************" << std::endl;

    return (Error == 0) ? 0 : 1;
}

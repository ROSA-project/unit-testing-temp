#include "gtest/gtest.h"
#include "sphereIntersection.h"

TEST(IntrsctionTest, NoIntersection) {
    Point c1 = {1, 4, 9};
    double r1 = 5.0;
    Point c2 = {20, 15, 25};
    double r2 = 3.0;

    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 0.0);
  
    c1 = {1, 4, 9};
    r1 = 5.0;
    c2 = {7, 0, 7};
    r2 = 3.0;
    /*
    volume of s1 : 523.599
    volume of s2 : 113.097
    Volume vcap1: 0.555769
    Volume vcap2: 0.973426
    Volume vcap2+vcap1 : 1.5292
    Threshold volume: 1.69646
    Intersection volume is below the threshold, treating as no intersection
    Intersection Volume: 0 */
    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 0.0);

    c1 = {0, 0, 0};
    r1 = 5.0;
    c2 = {1, 4,9 };
    r2 = 5.0;
    /*
    volume of s1 : 523.599
    volume of s2 : 523.599
    Volume vcap1: 0.0395347
    Volume vcap2: 0.0395347
    Volume vcap2  +vcap1 : 0.0790694
    Threshold volume: 7.85398
    Intersection volume is below the threshold, treating as no intersection
*/
    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 0.0);
}

TEST(IntrsctionTest, PartialIntersection) {
    Point c1 = {1, 4, 9};
    double r1 = 5.0;
    Point c2 = {2, 0, 7};
    double r2 = 2.0;
    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 19.415981738039619);

    c1 = {1, 4, 9};
    r1 = 5.0;
    c2 = {6, 0, 7};
    r2 = 3.0;
    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 9.1391194329659378);
}

TEST(IntrsctionTest, OuterTangency) {
    Point c1 = {1, 4, 9};
    double r1 = 5.0;
    Point c2 = {11, 4, 9};
    double r2 = 5.0;

    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 0.0);
}

TEST(IntrsctionTest, InnerTangency) {
    Point c1 = {0, 0, 0};
    double r1 = 1.5;
    Point c2 = {-0.5, 0 , 0 };
    double r2 = 1.0;
   
    double volume = sphereIntersection(c1, c2, r1, r2);

    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 4.1887866666666662 );
}

TEST(SphereIntersectionVolumeTest, oneSphereInsideAnother) {
    Point c1 {-10.5, -10.5, -10.5}; 
    double r1 = 8.0;                
    Point c2 {-11.0, -11.0, -11.0}; 
    double r2 = 2.0; 
    double volume = sphereIntersection(c1, c2, r1, r2);

    EXPECT_DOUBLE_EQ(sphereIntersection(c1, c2, r1, r2), 33.51029333333333 );
}


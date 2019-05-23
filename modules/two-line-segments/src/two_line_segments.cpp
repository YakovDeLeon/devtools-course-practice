// Copyright 2019 Iamshchikov Ivan

#include "include/two_line_segments.h"
#include <algorithm>

TwoLineSegments::TwoLineSegments(const LineSegment _ls1,
                                 const LineSegment _ls2) {
    ls1_.p1.SetCoordinatesToPoint(_ls1.p1.GetX(), _ls1.p1.GetY());
    ls1_.p2.SetCoordinatesToPoint(_ls1.p2.GetX(), _ls1.p2.GetY());
    ls2_.p1.SetCoordinatesToPoint(_ls2.p1.GetX(), _ls2.p1.GetY());
    ls2_.p2.SetCoordinatesToPoint(_ls2.p2.GetX(), _ls2.p2.GetY());
}

TwoLineSegments::TwoLineSegments(const TwoLineSegments& z) {
    ls1_.p1.SetCoordinatesToPoint(z.ls1_.p1.GetX(), z.ls1_.p1.GetY());
    ls1_.p2.SetCoordinatesToPoint(z.ls1_.p2.GetX(), z.ls1_.p2.GetY());
    ls2_.p1.SetCoordinatesToPoint(z.ls2_.p1.GetX(), z.ls2_.p1.GetY());
    ls2_.p2.SetCoordinatesToPoint(z.ls2_.p2.GetX(), z.ls2_.p2.GetY());
}

void TwoLineSegments::SetCoordinatesToFirstLine(const Point _p1,
                                                const Point _p2) {
    ls1_.p1.SetCoordinatesToPoint(_p1.GetX(), _p1.GetY());
    ls1_.p2.SetCoordinatesToPoint(_p2.GetX(), _p2.GetY());
}

void TwoLineSegments::SetCoordinatesToSecondLine(const Point _p1,
                                                const Point _p2) {
    ls2_.p1.SetCoordinatesToPoint(_p1.GetX(), _p1.GetY());
    ls2_.p2.SetCoordinatesToPoint(_p2.GetX(), _p2.GetY());
}

LineSegment TwoLineSegments::GetLineSegment1() const {
    return ls1_;
}

LineSegment TwoLineSegments::GetLineSegment2() const {
    return ls2_;
}

int TwoLineSegments::SignOfSquare(Point p1, Point p2, Point p3) const {
    int tmp = (p1.GetX() - p3.GetX())*(p2.GetY() - p3.GetY()) +
              (p2.GetX() - p3.GetX())*(p3.GetY() - p1.GetY());
    if (tmp > 0)
        return 1;
    if (tmp < 0)
        return -1;
    return 0;
}

bool TwoLineSegments::IsMax(int a, int b, int c, int d) const {
    return std::max(a, b) >= std::min(c, d) &&
           std::max(c, d) >= std::min(a, b);
}

bool TwoLineSegments::AreIntersect() const {
    int s11 = SignOfSquare(ls1_.p1, ls1_.p2, ls2_.p1);
    int s12 = SignOfSquare(ls1_.p1, ls1_.p2, ls2_.p2);
    int s21 = SignOfSquare(ls2_.p1, ls2_.p2, ls1_.p1);
    int s22 = SignOfSquare(ls2_.p1, ls2_.p2, ls1_.p2);

    if (s11 == 0 && s12 == 0 && s21 == 0 && s22 == 0)
        return IsMax(ls1_.p1.GetX(), ls1_.p2.GetX(),
                     ls2_.p1.GetX(), ls2_.p2.GetX()) &&
               IsMax(ls1_.p1.GetY(), ls1_.p2.GetY(),
                     ls2_.p1.GetY(), ls2_.p2.GetY());

    return (s11*s12 <= 0) && (s21*s22 <= 0);
}

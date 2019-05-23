// CopyRight 2019 Iamshchikov Ivan

#ifndef MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_H_
#define MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_H_

class Point {
 private:
    int x;
    int y;

 public:
    Point() = default;
    int GetX() const {
        return x;
    }

    int GetY() const {
        return y;
    }

    void SetCoordinatesToPoint(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct LineSegment {
    LineSegment() = default;
    Point p1;
    Point p2;
};

class TwoLineSegments {
 public:
    TwoLineSegments() = default;
    TwoLineSegments(const LineSegment _ls1,
                    const LineSegment _ls2);
    TwoLineSegments(const TwoLineSegments& z);

    void SetCoordinatesToFirstLine(const Point _p1, const Point _p2);
    void SetCoordinatesToSecondLine(const Point _p1, const Point _p2);

    LineSegment GetLineSegment1() const;
    LineSegment GetLineSegment2() const;

    bool AreIntersect() const;

 private:
    int SignOfSquare(Point p1, Point p2, Point p3) const;
    bool IsMax(int a, int b, int c, int d) const;
    LineSegment ls1_;
    LineSegment ls2_;
};


#endif  // MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_H_

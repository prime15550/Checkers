#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <piece.h>
#include <QGraphicsSceneMouseEvent>

class Piece;

class Boxe:public QGraphicsRectItem
{
public:
    Boxe(QGraphicsItem *parent=0);
    ~Boxe();
    void setRECT(int width,int height);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);
    void placePiece(Piece *piece); 


    void resetOriginalColor();
    void setOriginalColor(QColor value);

    bool getHasPiece();
    void setHasPiece(bool value,Piece *piece = 0);

    void checkForCheck();

    QString getPieceColor() ;
    void setPieceColor(QString value);

    int rowLoc;
    int colLoc;

    Piece * currentPiece;
    void undo();
private:
    QBrush brush;
    QColor originalColor;
    bool hasPiece;
    QString PieceColor;



};

#endif // BOX_H

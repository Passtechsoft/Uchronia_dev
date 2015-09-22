import sfml as sf

## A polygon collision function that use triangle computation
# @param pointsPoly Points parts of the polygon
# @param point The point to test
def polyCollision(pointsPoly, point)
  for i in pointsPoly:
     A = pointsPoly[i]
     B = sf.Vector2()
     
     if i==len(pointsPoly)-1:  # si c'est le dernier point, on relie au premier
         B = pointsPoly[0]
     else           # sinon on relie au suivant.
         B = pointsPoly[i+1]
         
     D,T=sf.Vector2()
     D.x = B.x - A.x
     D.y = B.y - A.y
     T.x = P.x - A.x
     T.y = P.y - A.y
     d = D.x*T.y - D.y*T.x
     if d<0:
        return False  # un point à droite et on arrête tout.
  return True  # si on sort du for, c'est qu'aucun point n'est à gauche, donc c'est bon.

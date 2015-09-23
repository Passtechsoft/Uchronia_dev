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
  
# Main Zone:
window = sf.RenderWindow(sf.VideoMode(640, 480), "pySFML Window")

try:
   # load a sprite to display
   texture = sf.Texture.from_file("cute_image.png")
   sprite = sf.Sprite(texture)
   

   # create some graphical text to display
   font = sf.Font.from_file("arial.ttf")
   text = sf.Text("Hello SFML", font, 50)

   # load music to play
   music = sf.Music.from_file("nice_music.ogg")

except IOError: exit(1)

# start the game loop
while window.is_open:
   # process events
   for event in window.events:
      # close window: exit
      if type(event) is sf.CloseEvent:
         window.close()

   window.clear() # clear screen
   window.draw(sprite) # draw the sprite
   window.draw(text) # draw the string
   window.display() # update the window

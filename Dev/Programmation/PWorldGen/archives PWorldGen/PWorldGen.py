# On importe Tkinter
from tkinter import *

screenWidth = 970
screenHeight = 600

class Interface(Frame):
	"""Notre fenêtre principale.

	Tous les widgets sont stockés comme attributs de cette fenêtre."""

	def __init__(self, fenetre, **kwargs):

		Frame.__init__(self, fenetre, width=screenWidth, height=screenHeight, **kwargs)
		self.pack(fill=BOTH)

		self.nb_clic = 0

		# Création de nos widgets
		self.message = Label(self, text="Vous n'avez pas cliqué sur le bouton.")

		self.message.pack()

		self.bouton_quitter = Button(self, text="Quitter", command=self.quit)

		self.bouton_quitter.pack(side="left")

		self.bouton_cliquer = Button(self, text="Cliquez ici", fg="red", command=self.cliquer)

		self.bouton_cliquer.pack(side="right")

	def cliquer(self):

		"""Il y a eu un clic sur le bouton.
		On change la valeur du label message."""

		self.nb_clic += 1

		self.message["text"] = "Vous avez cliqué {} fois.".format(self.nb_clic)

fenetre = Tk()

interface = Interface(fenetre)


interface.mainloop()

interface.destroy()


"""
import sfml as sf
import 
import time

## A polygon collision function that use triangle computation
# @param pointsPoly Points parts of the polygon
# @param point The point to test


  
# Main Zone:
window = sf.RenderWindow(sf.VideoMode(screenWidth, screenHeight), "Pangea World Generator")

def startIntro():
	# load a sprite to display
	pangeaTex = sf.Texture.from_file("pangea logo.png")
	triangleTex = sf.Texture.from_file("thetriangle.png")
	
	pangeaSprite = sf.Sprite(pangeaTex)
	triangleSprite = sf.Sprite(triangleTex)
	triangleSprite.ratio = sf.Vector2(.5, .5)
	pangeaSprite.position = sf.Vector2(0, 0)
	triangleSprite.position = sf.Vector2(screenWidth-triangleTex.width/2, 0)
	window.clear()
	
	window.draw(pangeaSprite)
	window.draw(triangleSprite)
	window.display() # update the window
	time.sleep(2)
	
def refreshInterface()
	rectangle = sf.RectangleShape()
	rectangle.position = sf.Vector2(screenWidth/2, 20)

#main:
startIntro()

# start the game loop
while window.is_open:
   # process events
   for event in window.events:
      # close window: exit
      if type(event) is sf.CloseEvent:
         window.close()
      else if(type(event)il révise et mange

   window.clear() # clear screen
   window.display() # update the window
"""

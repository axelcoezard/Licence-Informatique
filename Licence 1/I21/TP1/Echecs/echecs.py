import tkinter as tk
from PIL import Image, ImageTk  
from deplacement import cases_reine, \
    cases_tour, \
    cases_fou, \
    cases_roi, \
    cases_cavalier, \
    cases_pion

COTE = 50
NBC = 8
HA, LA = (NBC)*COTE+1, (NBC)*COTE+1
COULEUR = ['Cornsilk','Sienna']
ETAT_OFF     = 0
ETAT_ROI     = 1
ETAT_REINE   = 2
ETAT_FOU     = 3
ETAT_CAVALIER= 4
ETAT_TOUR    = 5
ETAT_PION    = 6





class Canevas(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.root = parent
        self.cote = COTE
        self.nbc = NBC
        self.la = LA
        self.ha = HA
        self.etat = ETAT_OFF
        self.canevas = tk.Canvas(self, 
                                 width=self.la,
                                 height=self.ha,
                                 bg='white')
        self.canevas.pack(fill="both",expand=True)
        self.canevas.bind("<Button-1>", self.click)
        self.board=[]
        self.init_board()

    def change_etat(self, e):
        self.etat = e

    def etat_reine(self):
        self.change_etat(ETAT_REINE)
        

    def etat_roi(self):
        self.change_etat(ETAT_ROI)

    def etat_cavalier(self):
        self.change_etat(ETAT_CAVALIER)

    def etat_fou(self):
        self.change_etat(ETAT_FOU)

    def etat_tour(self):
        self.change_etat(ETAT_TOUR)

    def etat_pion(self):
        self.change_etat(ETAT_PION)

    def delete_board(self):
        for ligne in self.board:
            for case in ligne:
                self.canevas.delete(case)
        self.init_board()
        
    def init_board(self):
        self.board = [[] for i in range(self.nbc)]
        for i in range(self.nbc):
            for j in range(self.nbc):
                self.board[i].append(self.canevas.create_rectangle(i*COTE+1, j*COTE+1,
                                                                   (i+1)*COTE+1, (j+1)*COTE+1,
                                                                   fill=COULEUR[(i+j)%2]))
    def numero_case(self, event):
        return event.y // COTE, event.x // COTE

    def colorer(self,cases):
        self.delete_board()
        for case in cases:
            self.canevas.itemconfig(self.board[case[0]][case[1]], fill='LightGreen')
        
            
    def dessiner_piece(self, col, lig):
        self.canevas.create_image((col+0.5)*COTE,(lig+0.5)*COTE,image=self.root.images[self.etat-1])
        
    def click(self,event):
        lig, col = self.numero_case(event) 
        if self.etat == ETAT_ROI:
            self.colorer(cases_roi(col, lig))
            self.dessiner_piece(col, lig)
        if self.etat == ETAT_REINE:
            self.colorer(cases_reine(col, lig))
            self.dessiner_piece(col, lig)
        if self.etat == ETAT_FOU:
            self.colorer(cases_fou(col, lig))
            self.dessiner_piece(col, lig) 
        if self.etat == ETAT_CAVALIER:
            self.colorer(cases_cavalier(col, lig)) 
            self.dessiner_piece(col, lig)
        if self.etat == ETAT_TOUR:
            self.colorer(cases_tour(col, lig))
            self.dessiner_piece(col, lig)
        if self.etat == ETAT_PION:
            self.colorer(cases_pion(col, lig))
            self.dessiner_piece(col, lig)
        
class Boutons(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.canevas = parent.canevas
        self.lcase = []
        self.icase = 0
        self.boutons=[]
        self.boutons.append(self.init_bouton("roi.png", 
                                             self.canevas.etat_roi))
        self.boutons.append(self.init_bouton("reine.png", 
                                             self.canevas.etat_reine))
        self.boutons.append(self.init_bouton("fou.png", 
                                             self.canevas.etat_fou))
        self.boutons.append(self.init_bouton("cavalier.png", 
                                             self.canevas.etat_cavalier))
        self.boutons.append(self.init_bouton("tour.png", 
                                             self.canevas.etat_tour))
        self.boutons.append(self.init_bouton("pion.png", 
                                             self.canevas.etat_pion))
        
    def init_bouton(self,img_name, cmd):
        image = Image.open(img_name)
        img = ImageTk.PhotoImage(image)
        bouton= tk.Button(self,image=img, command=cmd)
        bouton.image = img # keep a reference!
        bouton.pack()
        return bouton
        
             
class MainApp(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.root = parent
        self.root.title("Echecs")
        self.canevas = Canevas(self)
        self.canevas.pack(side="right", padx=10, pady=10, fill="both", expand=True)
        self.boutons = Boutons(self)
        self.boutons.pack(side="right", padx=10, pady=10, fill="both", expand=True)
        self.img_name = ["roi.png","reine.png","fou.png","cavalier.png","tour.png","pion.png"]
        self.init_images()
        
    def init_images(self):
        self.images=[]
        for name in self.img_name:
            image = Image.open(name)
            imgage=image.resize((10,10),Image.ANTIALIAS)
            img = ImageTk.PhotoImage(image)
            
            self.images.append(img)

    def mainloop(self):
        self.root.mainloop()

if __name__=='__main__':
    App = MainApp(tk.Tk())
    App.pack(side="top", fill="both", expand=True)
    App.mainloop()



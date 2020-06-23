import tkinter as tk
from random import randrange, shuffle
from tripancake import tri_pancake

PAUSE = 10
NB_PANCAKE = 160
UNITE_DIAMETRE = 6.25
EPAISSEUR = 2.5
ETAT_OFF = 0
ETAT_ON = 1

class Info(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.root = parent

        self.essaie = tk.Frame(self)
        self.difficulte = tk.Frame(self)
        self.algo= tk.Frame(self)

        # La zone d'affichage du nombre d'essaies
        self.var_essaie = tk.StringVar()
        self.var_max = tk.StringVar()
        self.nbessaies = tk.Label(self.essaie,
                                  textvariable=self.var_essaie,
                                  font=("Helvetica",16))
        self.maxi = tk.Label(self.essaie,
                               textvariable=self.var_max,
                               font=("Helvetica",16))
        self.bar =  tk.Label(self.essaie,
                             text=" / ",
                             font=("Helvetica",16))
        self.maxi.pack(side="right",expand=False)
        self.bar.pack(side="right",expand=False)
        self.nbessaies.pack(side="right",expand=False)
        self.update_info()

        # La zone de select80ion du nombre de pancakes
        self.var_diff = tk.IntVar()
        self.mode = tk.Scale(self.difficulte,
                             variable = self.var_diff,
                             from_ = 3,
                             to_ = 160,
                             orient = tk.HORIZONTAL,
                             label = "Nb pancakes")
        self.restart = tk.Button(self.difficulte,
                                 text = "Restart",
                                 command=self.root.restart)
        self.mode.pack(side="top", expand=False)
        self.restart.pack(side="top", expand=False)

        # Le bouton pour déclencher l'algorithme
        self.tri = tk.Button(self.difficulte,
                             text = "Tri auto",
                             command=self.root.canevas.bouton_tri_pancake)
        self.tri.pack()

        self.essaie.pack(side="top", expand=False)
        self.difficulte.pack(side="top", expand=False)
        self.algo.pack(side="top", expand=False)

    def update_info(self):
        self.var_essaie.set(str(self.root.canevas.nbessaies))
        self.var_max.set(str(self.root.canevas.essaiemax))


class Canevas(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.root = parent
        self.etat = ETAT_OFF
        self.nbpancake = 160
        self.pile_dessin = []
        self.canevas = tk.Canvas(self, bg='white')
        self.canevas.pack(padx=10,pady=10,expand=True)
        self.init_pile()

        self.canevas.bind("<Button-1>", self.click)

    def bouton_tri_pancake(self):
        self.l_ind = tri_pancake(self.pile[:])
        self.i = 0
        self.tri()


    def allumer(self,i):
        self.canevas.itemconfig(self.pile_dessin[i], fill = 'LightGreen')

    def eteindre(self,i):
        self.canevas.itemconfig(self.pile_dessin[i], fill = 'SaddleBrown')

    def tri(self):
        if self.i >= len(self.l_ind):
            return
        if self.etat == ETAT_OFF:
            self.allumer(self.l_ind[self.i])
            self.etat = ETAT_ON
            self.after(PAUSE, self.tri)
        else:
            self.eteindre(self.l_ind[self.i])
            self.retourner_pile(self.l_ind[self.i])
            self.etat = ETAT_OFF
            self.i += 1
            self.after(PAUSE, self.tri)

    def init_pile(self):
        self.efface_pile()
        self.nbessaies = 0
        self.essaiemax = 0
        self.la = (self.nbpancake+2)*UNITE_DIAMETRE
        self.ha = (self.nbpancake+2)*EPAISSEUR
        self.canevas.config(width=self.la, height=self.ha)
        self.pile = [i for i in range(1,self.nbpancake+1)]
        self.melange_pile()
        self.dessine_pile()
        self.essaie_max()

    def melange_pile(self):
        shuffle(self.pile)

    def dessine_pancake(self, x,y,d):
        return self.canevas.create_rectangle(x,y,
                                             x+d*UNITE_DIAMETRE,y+EPAISSEUR,
                                             fill="SaddleBrown",
                                             outline="Wheat",
                                             width=3,
                                             activefill="limegreen")
    def dessine_pile(self):
        self.efface_pile()
        for i in range(len(self.pile)):
            d = self.pile[i]
            x = (self.la - d*UNITE_DIAMETRE)/2
            y = self.ha - EPAISSEUR*(i+1)
            self.pile_dessin.append(self.dessine_pancake(x,y,d))

    def efface_pile(self):
        for p in self.pile_dessin:
            self.canevas.delete(p)
        self.pile_dessin=[]

    def retourner_pile(self, i):
        self.pile = self.pile[:i]+self.pile[i:][::-1]
        self.dessine_pile()
        self.nbessaies += 1
        self.root.info.update_info()

    def click(self,event):
        x,y = event.x, event.y
        over=self.canevas.find_overlapping(x, y, x, y)
        if over:
            p=over[-1]
        i = self.pile_dessin.index(p)
        self.retourner_pile(i)

    def essaie_max(self):
        pile = self.pile[:]
        n=0
        for i in range(len(pile)-1):
            j = pile.index(max(pile[i:]))
            if j!= i:
                if j!=len(pile)-1:
                    pile = pile[:j]+pile[j:][::-1]
                    n += 1
                pile = pile[:i]+pile[i:][::-1]
                n += 1
        self.essaiemax = n


class MainApp(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.root = parent
        self.root.title("Tri Pancake")
        self.canevas = Canevas(self)
        self.canevas.pack(side="right",
                       padx=10,pady=10,
                       fill="both",expand=False)
        self.info = Info(self)
        self.info.pack(side="left",
                       padx=10,pady=10,
                       fill="both",expand=False)

    def mainloop(self):
        self.root.mainloop()

    def restart(self):
        self.canevas.nbpancake = self.info.var_diff.get()
        self.canevas.init_pile()
        self.info.var_essaie.set(str(self.canevas.nbessaies))
        self.info.var_max.set(str(self.canevas.essaiemax))


if __name__=='__main__':
    App = MainApp(tk.Tk())
    App.pack(side="top", fill="both", expand=False)
    App.mainloop()

import tkinter as tk
from time import sleep
from parcours import       \
    parcours_ligne,        \
    parcours_colonne,      \
    parcours_diagonal,     \
    parcours_antidiagonal, \
    parcours_sinusoidal,   \
    parcours_zigzag,       \
    parcours_serpentin

PAUSE = 80
COTE = 50
NBC = 10
HA, LA = (NBC)*COTE+1, (NBC)*COTE+1

class Canevas(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.cote = COTE
        self.nbc = NBC
        self.la = LA
        self.ha = HA
        self.canevas = tk.Canvas(self, 
                                 width=self.la,
                                 height=self.ha,
                                 bg='white')
        self.canevas.pack(fill="both",expand=True)
        self.matrix=[]
        self.init_matrix()

    def delete_matrix(self):
        for ligne in self.matrix:
            for case in ligne:
                self.canevas.delete(case)
        
    def init_matrix(self):
        self.matrix = [[] for i in range(self.nbc)]
        for i in range(NBC):
            for j in range(NBC):
                self.matrix[i].append(self.canevas.create_rectangle(i*COTE+1, j*COTE+1, 
                                                                    (i+1)*COTE+1, (j+1)*COTE+1))
        
        
    def colorer(self,i,j):
        self.canevas.itemconfig(self.matrix[i][j], fill='red')
        

class Parcours(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.canevas = parent.canevas
        self.lcase = []
        self.icase = 0
        self.boutons = [ tk.Button(self, text="Ligne",  
                                   command=self.dessine_ligne,
                                   width=10, height=3), 
                         tk.Button(self, text="Colonne",  
                                   command=self.dessine_colonne,
                                   width=10, height=3), 
                         tk.Button(self, text="Diagonal",  
                                   command=self.dessine_diagonal,
                                   width=10, height=3), 
                         tk.Button(self, text="Antidiagonal",  
                                   command=self.dessine_antidiagonal,
                                   width=10, height=3),
                         tk.Button(self, text="Sinusoidal",  
                                   command=self.dessine_sinusoidal,
                                   width=10, height=3),
                         tk.Button(self, text="ZigZag",  
                                   command=self.dessine_zigzag,
                                   width=10, height=3),
                         tk.Button(self, text="Serpentin",  
                                   command=self.dessine_serpentin,
                                   width=10, height=3) ]
        self.PackButton()
        
    def PackButton(self):
        for button in self.boutons[::-1]:
            button.pack(side = "bottom", padx=5, pady=5)

    def dessine(self):
        self.canevas.colorer(self.lcase[self.icase][0],self.lcase[self.icase][1])
        self.icase += 1
        if self.icase < len(self.lcase):
            self.after(PAUSE, self.dessine)


    def dessine_ligne(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_ligne(self.canevas.nbc)
        self.icase = 0
        self.dessine()
                
    def dessine_colonne(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_colonne(self.canevas.nbc)
        self.icase = 0
        self.dessine()
       
         
    def dessine_diagonal(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_diagonal(self.canevas.nbc)
        self.icase = 0
        self.dessine()

    def dessine_antidiagonal(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_antidiagonal(self.canevas.nbc)
        self.icase = 0
        self.dessine()

    def dessine_sinusoidal(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_sinusoidal(self.canevas.nbc)
        self.icase = 0
        self.dessine()

    def dessine_zigzag(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_zigzag(self.canevas.nbc)
        self.icase = 0
        self.dessine()
    
    def dessine_serpentin(self):
        self.canevas.delete_matrix()
        self.canevas.init_matrix()
        self.lcase = parcours_serpentin(self.canevas.nbc)
        self.icase = 0
        self.dessine()
             
class MainApp(tk.Frame):
    def __init__(self, parent, *args, **kwargs):
        tk.Frame.__init__(self, parent, *args, **kwargs)
        self.root = parent
        self.root.title("Parcours de tableau")
        self.canevas = Canevas(self)
        self.canevas.pack(side="right", padx=10, pady=10, fill="both", expand=True)
        self.parcours = Parcours(self)
        self.parcours.pack(side="right", padx=10, pady=10, fill="both", expand=True)
               

    def mainloop(self):
        self.root.mainloop()

if __name__=='__main__':
    App = MainApp(tk.Tk())
    App.pack(side="top", fill="both", expand=True)
    App.mainloop()



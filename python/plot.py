import networkx as nx
import matplotlib.pyplot as plt

G = nx.read_graphml('results.graphml')

nx.draw(G,with_labels=True)
plt.show()

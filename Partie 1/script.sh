mkdir graphes
cd ./graphes
mkdir results
cd ..

./symetrique ./graphes/alea_100_500.graphe ./graphes/results/resultat_alea_100_500.graphe
./symetrique ./graphes/alea_1000_5000.graphe ./graphes/results/resultat_alea_1000_5000.graphe
./symetrique ./graphes/alea_10000_50000.graphe ./graphes/results/resultat_alea_10000_50000.graphe
./symetrique ./graphes/alea_10000_150000.graphe ./graphes/results/resultat_alea_10000_150000.graphe
./symetrique ./graphes/alea_10000_200000.graphe ./graphes/results/resultat_alea_10000_200000.graphe
./symetrique ./graphes/alea_10000_300000.graphe ./graphes/results/resultat_alea_10000_300000.graphe
./symetrique ./graphes/alea_100000_500000.graphe ./graphes/results/resultat_alea_100000_500000.graphe

./symetrique ./graphes/pistes.petit.graphe ./graphes/results/resultat_pistes.petit.graphe
./symetrique ./graphes/pistes.large.graphe ./graphes/results/resultat_pistes.large.graphe

echo "Terminé avec succès"
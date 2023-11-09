# group_x

Esimerkkinä yksinkertainen oppilaitoksen tietokanta.

Aluksi hahmottelin sovelluksen toimintaa

<img src="ui_kuva.png">

Ja edellisen perusteella tietokannan ER-diagrammia

<img src="er_plan.png">

Ja tästä lopullinen ER-kaavio

<img src="final_er.png">

## Tietokanta yhteys

Luodaan tunnus jolla sovelluksesta kytkeydytään tietokantaan

<pre>
create user peppiuser@'localhost' identified by 'peppipass';
grant all on peppi.* to peppiuser@'localhost';
</pre>

## .env

Jotta sovellus toimii, pitää backend-kansion juureen laittaa tiedosto **.env**, jossa on rivi 
<pre>
MY_TOKEN=ITe8HWkbIKzbG+oVPyj75BkBUUc5Jdw/q9qNvxD+ZYVDhXLm6fAWg3EqGOmBuduIy2GkQbBpnr11mr13DKZBmQ==
</pre>

Poistan tiedoston reposta, koska repo on public-tyyppinen, joten GitHub alkaa lähettämään minulle emailia, jossa varoittaa tietoturvasta.

Ja lisään .gitignoreen rivin
<pre>
backend/.env
</pre>

## Tietokanta yhteys .env:ssä

Jos backendin haluaa viedä johonkin pilvipalveluun (esim. Render), kannattaa tietokannan "määritys-stringi" kirjoittaa ympäristömuuttujiin. 
Tässä esimerkissä lisäsin **.env**-tiedostoon rivin 
<pre>
SQL_SERVER=mysql://peppiuser:peppipass@localhost:3306/peppi
</pre>
Ja sitten Renderissä luon "environment muuttujan" nimeltään SQL_SERVER, mutta siinä viittaan eri tietokantaan, joka minulla on **db4free.net**-palvelussa.
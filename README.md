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
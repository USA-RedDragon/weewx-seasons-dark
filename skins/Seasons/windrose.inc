## windrose module for weewx skins
## Copyright Tom Keffer, Matthew Wall
## See LICENSE.txt for your rights
#errorCatcher Echo
#encoding UTF-8

<div id='windrose_widget' class="widget">
  <div class="widget_title">
    Windrose
    <a class="widget_control"
      onclick="toggle_widget('windrose')">&diams;</a>
  </div>

  <div class="widget_contents">
    <img src="daywindrose.png?nocache=$current.dateTime" alt="Windrose" />
  </div>
</div>

## Copyright John A Kline
## See LICENSE.txt for your rights
#errorCatcher Echo
#encoding UTF-8
<div>
  <table style='width:100%;padding-left:5em; padding-right:5em;'>
    #set $title_font_size = '16px'
    #for $twelve_hour in $nwsforecast.twelve_hour_forecasts()
    #set $forecast_generated_at = $twelve_hour.generatedTime ##.format('%a %l %p')
    <tr>
      <td>
        ## ------------------------------------------------
        ## |       |               |                       |
        ## |       |     Temp      |     Memorial Day      |
        ## |       |     78 F      |-----------------------|
        ## | ICON  | rising slowly |  Partly cloudy with   |
        ## |       |      Wind     |  high of 84.  Winds   |
        ## |       |   1 mph NNW   |  between 1 and 9 mph  |
        ## |       |               |                       |
        ## -------------------------------------------------
        <table style='width:100%;border-bottom:1pt dotted LightGray;padding:0.5em;'>
          #set $curtemp = $twelve_hour.outTemp.value_t[0]
          #set $cold = $curtemp < 50
          #set $hot = $curtemp > 78
          <tr>
            #set $icon = $twelve_hour.iconUrl
            <td style='width:16%;'><img src='$icon' alt='$icon'></td>
            <td style='width:30%;'>
              <table style='width:100%;text-align:center;'>
                <tr style='width:100%;'><td>
                  #if $cold
                    <span class="temp-cold">
                  #end if
                  #if $hot
                    <span class="temp-hot">
                  #end if
                  #if not $hot and not $cold
                    <span class="temp-norm">
                  #end if
                  #include "icons/temperature.svg"
                  </span>
                  $twelve_hour.outTemp.format('%.0f')$unit.label.outTemp $twelve_hour.outTempTrend
                </td></tr>
                <tr style='width:100%;'><td>
                  #if $cold
                    <span class="temp-cold">
                  #end if
                  #if $hot
                    <span class="temp-hot">
                  #end if
                  #if not $hot and not $cold
                    <span class="temp-norm">
                  #end if
                  #include "icons/wind.svg"
                  </span>
                  $twelve_hour.windSpeed.format('%.0f')$unit.label.windSpeed $twelve_hour.windDir.ordinal_compass
                </td></tr>
              </table>
            </td>
            <td style='width:54%;'>
              <table style='width:100%;'>
                <tr style='width:100%;'><td style='text-align:center;font-size:$title_font_size;font-weight:bold;border-bottom:1px solid LightGray;'>$twelve_hour.name</td></tr>
                <tr style='font-size:14px; width:100%;'><td>$twelve_hour.detailedForecast</td></tr>
              </table>
            </td>
          </tr>
        </table>
      </td>
    </tr>
    #end for
    #set $forecast_generated_at = $current.dateTime
    #if $forecast_generated_at != ''
    <tr>
      <td style='text-align:center;font-style:italic;color:Gray;'>Forecast generated $forecast_generated_at.</td>
    </tr>
    #end if
  </table>
</div>

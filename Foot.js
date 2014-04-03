
);

  var options = {
    title: 'Test Results, (nanoseconds)'
  };

  var chart = new google.visualization.LineChart(document.getElementById('chart_div'));
  chart.draw(data, options);
}

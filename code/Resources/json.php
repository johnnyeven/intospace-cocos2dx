<?php
$config = array(
	'mapPListFilePath'				=>	'images/maps/A-1-2.plist',
	'spriteFrameName'				=>	'A-1-2.png',
	'stations'						=>	array(
		array(
			'resource'				=>	'images/stations/space_station_blue.png',
			'zIndex'				=>	0.01,
			'blockX'				=>	1,
			'blockY'				=>	0,
			'positionX'				=>	10500,
			'positionY'				=>	2000
		)
	)
);

echo json_encode($config);
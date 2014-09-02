<?php
$config = array(
	'mapPListFilePath'				=>	'images/maps/A-1-2.plist',
	'mapSpriteFrameName'			=>	'A-1-2.png',
	'stationPListFilePath'			=>	'images/maps/stations/A-1-2.plist',
	'starPListFilePath'				=>	'images/maps/stars/A-1-2.plist',
	'stations'						=>	array(
		array(
			'resource'				=>	'star_0.png',
			'zIndex'				=>	0.05,
			'blockX'				=>	1,
			'blockY'				=>	0,
			'positionX'				=>	10500,
			'positionY'				=>	2000
		),
		array(
			'resource'				=>	'star_1.png',
			'zIndex'				=>	0.03,
			'blockX'				=>	1,
			'blockY'				=>	0,
			'positionX'				=>	10500,
			'positionY'				=>	2000
		),
		array(
			'resource'				=>	'space_station_blue.png',
			'zIndex'				=>	0.02,
			'blockX'				=>	1,
			'blockY'				=>	0,
			'positionX'				=>	10500,
			'positionY'				=>	2000
		)
	)
);

echo json_encode($config);
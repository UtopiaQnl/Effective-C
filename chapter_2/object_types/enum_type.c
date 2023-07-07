enum day { sun, mon, tue, wed, thu, fri, sat };
// Если не присвоить значение первому перечислителю с помощью опера ции =, то
// его перечисляемая константа будет равна 0, и каждый следующий перечислитель
// без знака = будет прибавлять 1 к предыдущей константе. Следовательно,
// значение sun в перечислении day равно 0, mon равно 1 и т. д.

enum cardinal_points { north = 0, east = 90, south = 180, west = 270 };
enum months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

// Использование операции = может привести к повторению значений, что чревато
// проблемами, если вы ошибочно предполагаете, будто все значения должны быть
// уникальными. В перечислении month первому перечислителю назначается 1, а
// значение каждого следующего перечислителя, который не задан явно, инкрементируется на 1

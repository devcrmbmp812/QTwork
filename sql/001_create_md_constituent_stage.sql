create table if not exists md_constituent_stage
(
	id serial not null
		constraint md_constituent_stage_id_pk
			primary key,
	date varchar(65535),
	constituent_ticker varchar(65535),
	coupon varchar(65535),
	cusip varchar(65535),
	isin varchar(65535),
	sedol varchar(65535),
	bbgid varchar(65535),
	ric varchar(65535),
	industry varchar(65535),
	subindustry varchar(65535),
	industry_group varchar(65535),
	sector varchar(65535),
	weight varchar(65535),
	created_at timestamp,
	updated_at timestamp,
	lock_revision integer
)
;

create unique index if not exists md_constituent_stage_id_uindex
	on md_constituent_stage (id)
;


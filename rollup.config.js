import resolve from 'rollup-plugin-node-resolve';
import commonjs from 'rollup-plugin-commonjs';
import babel from 'rollup-plugin-babel';
import filesize from 'rollup-plugin-filesize';
import copier from 'rollup-plugin-copier';
import pkg from './package.json';

export default [
	{
		input: 'lib/index.js',
		output: [
			{ file: pkg.main, format: 'cjs' },
			{ file: pkg.module, format: 'es' }
		],
		plugins: [
			resolve(),
      commonjs(),
      babel(),
      filesize(),
      copier({
        items: [
          {
            src: "lib/index.d.ts",
            dest : "dist/index.d.ts",
            createPath: true
          }
        ]
      })
		]
	}
];
